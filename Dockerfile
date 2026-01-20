FROM debian:13.2

RUN apt-get update && \
    apt-get install -y build-essential && \
    rm -rf /var/lib/apt/lists/*

COPY PR.deb /tmp/PR.deb

RUN dpkg -i /tmp/PR.deb || apt-get install -f -y

WORKDIR /usr/local/bin

CMD ["PR"]
