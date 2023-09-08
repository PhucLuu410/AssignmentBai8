#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc dữ liệu Queue
struct Queue {
    int front, rear, size, capacity;
    int* array;
};

// Hàm tạo một Queue mới với dung lượng cho trước
float createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // rear ban đầu ở cuối
    queue->array = (int*)malloc(sizeof(int) * capacity);
    return queue;
}

// Hàm kiểm tra xem Queue có đầy không
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Hàm kiểm tra xem Queue có trống không
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Hàm thêm một phần tử vào cuối Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Hàm lấy một phần tử ra khỏi đầu Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;  // Giá trị -1 để chỉ rằng Queue trống
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int main() {
    int capacity = 5;
    struct Queue* queue = createQueue(capacity);

    // Thêm các phần tử vào Queue
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    // Lấy ra các phần tử từ Queue và in ra
    printf("Cac phan tu trong Queue sau khi da them:\n");
    while (!isEmpty(queue)) {
        int item = dequeue(queue);
        printf("%d ", item);
    }

    return 0;
}
