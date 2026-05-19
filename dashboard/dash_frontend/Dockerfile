FROM rust:1.95

WORKDIR /dash_frontend

COPY . .

RUN cargo build

EXPOSE 8554

CMD ["cargo", "run"]
