FROM rust:1.95

WORKDIR /rust_api

COPY . .

RUN cargo build --release

EXPOSE 8080

CMD ["./target/release/rust_api"]
