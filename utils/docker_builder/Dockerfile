#For cross-compiler docker see https://github.com/dockcross/dockcross


FROM debian:buster-slim

# install common utilities
RUN apt-get update \
  && apt-get install --no-install-recommends -y \
    build-essential \
    libgmock-dev \
    libgtest-dev \
    python3 \
    python3-pytest \
    python3-pytest-cov \
    cmake \
    git \
    clang-format \
    cppcheck \
    valgrind \
    openssh-server \
    gdb-multiarch \
    rsync \
    net-tools \
    nano \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

# Enable ssh connection
RUN echo 'root:admin' | chpasswd
RUN sed -i 's/#PasswordAuthentication yes/PasswordAuthentication yes/g' /etc/ssh/sshd_config
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/g' /etc/ssh/sshd_config
RUN mkdir -p /run/sshd
EXPOSE 22
ENTRYPOINT service ssh restart && bash