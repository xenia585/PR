FROM debian:13.2

RUN apt-get update && \
    apt-get install -y build-essential && \
    rm -rf /var/lib/apt/lists/*

COPY pr.deb /tmp/pr.deb

RUN dpkg -i /tmp/pr.deb || apt-get install -f -y

WORKDIR /usr/local/bin

CMD ["pr"]
