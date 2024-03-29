ARG VARIANT="debian-12"
FROM mcr.microsoft.com/devcontainers/cpp:${VARIANT}

ENV LANG="en_US.UTF-8" \
    TZ="Asia/Taipei" \
    TERM="xterm-256color"

RUN set -xe && \
    echo "==== Setting locale ====" && \
    update-locale LANG=${LANG} && \
    echo "==== Setting timezone ====" && \
    unlink /etc/localtime && \
    ln -snf /usr/share/zoneinfo/${TZ} /etc/localtime && \
    echo ${TZ} > /etc/timezone

RUN echo "==== Installing dependency ====" && \
    apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y \
        libssl-dev \
        lld-16 \
        lldb-16 \
        clang-16 \
        clang-format-16 \
        clang-tidy-16 \
        clangd-16 \
        clang-tools-16 \
        doxygen \
        graphviz \
        xdot \
        dia \
        llvm-16-dev \
        libc++-16-dev \
        libc++abi-16-dev \
        libjsoncpp-dev \
        uuid-dev \
        zlib1g-dev \
        libc-ares-dev \
        libspdlog-dev \
        libyaml-cpp-dev \
        libbrotli-dev \
        libgtest-dev \
        libgmock-dev && \
    apt-get autoremove -y clang-14 && \
    apt-get clean -y && \
    rm -rf /var/lib/apt/lists/*

RUN echo "==== update alternatives clang ====" && \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-16 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-16 100 && \
    update-alternatives --install /usr/bin/lld lld /usr/bin/lld-16 100 && \
    update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-16 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-16 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-16 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-16 100

RUN echo "==== Installing hiredis from source ====" && \
    wget "https://github.com/redis/hiredis/archive/refs/tags/v1.2.0.tar.gz" -O "/tmp/hiredis.tar.gz" && \
    tar -xzf "/tmp/hiredis.tar.gz" -C "/tmp" && \
    cd "/tmp/hiredis-1.2.0" && \
    make && \
    make install && \
    rm -rf "/tmp/hiredis.tar.gz" "/tmp/hiredis-1.2.0"

ARG USERNAME=vscode