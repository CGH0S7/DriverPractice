#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // 打开设备文件
    int fd = open("/dev/example", O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }

    // 读取设备数据
    char buffer[128];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        perror("Failed to read from device");
    } else {
        printf("Read %zd bytes from device\n", bytes_read);
    }

    // 写入设备数据
    const char *data = "Hello, example device!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written < 0) {
        perror("Failed to write to device");
    } else {
        printf("Wrote %zd bytes to device\n", bytes_written);
    }

    // 关闭设备文件
    if (close(fd) < 0) {
        perror("Failed to close device");
    }

    return 0;
}