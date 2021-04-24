#For cross-compiler docker see https://github.com/dockcross/dockcross


FROM debian:buster-slim

# install common utilities
RUN apt-get update \
  && apt-get install --no-install-recommends -y \
    build-essential \
    clang-format \
    cmake \
    cppcheck \
    git \
    nano \
    openssh-server \
    gdb-multiarch \
    libgmock-dev \
    libgtest-dev \
    python3 \
    python3-pytest \
    python3-pytest-cov \
    valgrind \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*