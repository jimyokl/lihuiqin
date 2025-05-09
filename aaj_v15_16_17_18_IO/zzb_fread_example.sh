
二进制读取，unsigned char data[100]; FILE *fp = fopen("data.bin", "rb"); fread(data, 1, sizeof(data), fp);
为什么unsigned类型, bin文件是按字节存储的, bin数据本质上是一个个的字节（byte），每个字节8位，即0到255。

常见的 读取图片的 目的:
1. 显示图片 场景：图像浏览器、网页展示、GUI 程序等。
2. 图像处理 / 图像分析，场景：人脸识别、边缘检测、图像增强、滤波、修复等。
3. 计算机视觉 / AI 推理，场景：目标检测、图像分类、自动驾驶、医学图像分析等。
4. 数据存储与传输，场景：网络传输、数据库存储、打包图片资源。
5. 图像格式转换，场景：将 JPG 转为 PNG、BMP、RAW 等格式。
6. 元数据提取，场景：读取照片拍摄时间、设备信息、GPS 坐标（EXIF 数据）。


// ************~~~~~~~~~~~~~~~~~~~$$$$$$$$$****生成students.dat文件********~~~~~~~~~~~~~~~~~~~$$$$$$$$$
typedef struct {
    int id;
    float score;
    char name[20];
} Student;
int main() {
    Student students[2] = {
        {1, 90.5, "Alice"},
        {2, 85.0, "Bob"}
    };

    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        perror("无法创建文件");
        return 1;
    }
    fwrite(students, sizeof(Student), 2, fp); // 写入两个结构体
    fclose(fp);

    printf("写入成功\n"); return 0;
}
// ************~~~~~~~~~~~~~~~~~~~$$$$$$$$$****用fread从该文件中读取********~~~~~~~~~~~~~~~~~~~$$$$$$$$$
typedef struct {
    int id;
    float score;
    char name[20];
} Student;

int main() {
    FILE *fp = fopen("students.dat", "rb");  // 以二进制只读方式打开文件
    if (fp == NULL) {
        perror("无法打开文件"); return 1;
    }
    Student s;
    
    while (fread(&s, sizeof(Student), 1, fp) == 1) {          // 一次读取一个结构体
        printf("ID: %d, Name: %s, Score: %.2f\n", s.id, s.name, s.score);
    }

    fclose(fp); return 0;
}

// ************~~~~~~~~~~~~~~~~~~~$$$$$$$$$****eg2, 读图片********~~~~~~~~~~~~~~~~~~~$$$$$$$$$
int main() {
    FILE *file;
    char *buffer;
    long file_size;

    file = fopen("example.jpg", "rb");  //以二进制模式读取
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    fseek(file, 0, SEEK_END);  // 移动到文件末尾，获取文件大小
    file_size = ftell(file);
    rewind(file);
    
    buffer = (char *)malloc(sizeof(char) * file_size); // 分配内存存储文件内容
    if (buffer == NULL) {
        perror("内存分配失败");
        fclose(file);
        return 1;
    }
    
    size_t result = fread(buffer, 1, file_size, file); // 读取文件内容到缓冲区
    if (result != file_size) {
        perror("读取错误");
        free(buffer);
        fclose(file);
        return 1;
    }

    printf("读取了 %ld 字节的图片数据。\n", file_size);
    free(buffer); fclose(file); return 0;
}
