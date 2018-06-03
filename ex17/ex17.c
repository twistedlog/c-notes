#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100

// TODO check does malloc round off sizeof
struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

void Database_load(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to load Database");
  }
}


void Address_print(struct Address *addr){
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

struct Connection *Database_open(const char *filename, char mode){
  struct Connection *conn = malloc(sizeof(struct Connection));
if (!conn) {
    die("Memory Error");
  }
  conn->db = malloc(sizeof(struct Database));
  if (!conn->db) {
    die("Memory Error");
  }
  if (mode == 'c') {
    /*
    ``w'' Truncate to zero length or create text file for writing.
      The stream is positioned at the beginning of the file.
    */
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");
    if (conn->file) {
        Database_load(conn);
    }
  }

  if (!conn->file) {
    die("Failed to open database file");
  }
  return conn;
}

void Database_create(struct Connection *conn) {
  int i = 0;

  for (i=0; i<MAX_ROWS; i++){
    struct Address addr = {.id = i,.set = 0 };
    conn->db->rows[i] = addr;
  }
}

void Database_write(struct Connection *conn) {
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1){
    die("Failed to write to file");
  }
  rc = fflush(conn->file);
  if (rc == -1) {
    die("Cannot flush database");
  }
}

void Database_get(struct Connection *conn, int id){
  struct Address *addr = &conn->db->rows[id];

  if (addr->set){
    Address_print(addr);
  } else {
    die("ID is not set");
  }
}

void Database_set(struct Connection *conn, int id, char *name, char *email) {
  struct Address *addr = &conn->db->rows[id];
  if (addr->set){
      die("Alerady set, Delete it first");
  }
  addr->set = 1;
  char *res = strncpy(addr->name, name, MAX_DATA);
  if (!res) {
    die("Name copy failed");
  }
  res = strncpy(addr->email, email, MAX_DATA);
  if (!res) {
    die("Email copy failed");	  
  }
}

void Database_delete(struct Connection *conn, int id) {
    struct Address addr = {.id = id, .set =0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn){
    int i = 0;
    for (i=0; i<MAX_ROWS; i++) {
	struct Address *row = &conn->db->rows[i]; 
	if (row->set)
	  Address_print(row);
    }
}

void Database_close(struct Connection *conn){
  if (conn){
    if (conn->file){
      fclose(conn->file);
    }
    // TODO comment free conn->db and analyze in debugger or valgrind to find
    // memory leaks
    if (conn->db) {
      free(conn->db);
    }
    free(conn);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    die("USAGE: ex17 <dbfile> <action> [action params]");
  }
  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *conn = Database_open(filename, action);
  int id=0;
  if (argc > 3) id = atoi(argv[3]);
  if (id >= MAX_ROWS) die("There's not that many records");

  switch (action) {
    case 'c':
       Database_create(conn);
       Database_write(conn);
       break;
    case 'g':
       if (argc < 4) {
	  die("missing row argument");
       }
       Database_get(conn, id);
       break;
    case 's':
       if (argc < 6)
	  die("Need id, name, email to set");
       Database_set(conn, id, argv[4], argv[5]);
       Database_write(conn);
       break;
    case 'd':
       if (argc != 4)
          die("row id to be deleted is needed");
       Database_delete(conn, id);
       Database_write(conn);
       break;
    case 'l':
       Database_list(conn);
       break;
    default:
       die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }
  Database_close(conn);
  return 0;
}
