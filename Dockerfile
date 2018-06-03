FROM gcc:4.9
run apt-get update
run apt-get install -y build-essential valgrind vim
WORKDIR /app
ADD . /app
