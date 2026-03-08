FROM debian:13 AS dependencies

WORKDIR /app

# Get needed libraries for application
RUN apt-get update && \
    apt-get install -y \
    cmake \
    git \
    postgresql-server-dev-all \
    build-essential

# Install oat++
RUN git clone -b 1.3.0-latest https://github.com/oatpp/oatpp.git && \
    mkdir oatpp/build && \
    cd oatpp/build && \
    cmake .. -DOATPP_BUILD_TESTS=OFF && \
    make install

# Install oat++ orm connector for PostgreSQL
RUN git clone -b 1.3.0-latest https://github.com/oatpp/oatpp-postgresql.git && \
    mkdir oatpp-postgresql/build && \
    cd oatpp-postgresql/build && \
    cmake .. && \
    make install

FROM dependencies AS compile
WORKDIR /app

COPY . .

RUN mkdir build && cd build && \
    cmake .. && \
    make

# Clean image for running

FROM debian:13

WORKDIR /app

COPY --from=compile /app/build/main .

CMD ["./main"]