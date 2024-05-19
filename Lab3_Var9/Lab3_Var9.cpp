// Lab3_Var9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    void enqueue(const T& value) {
        Node* newNode = new Node{ value, nullptr };
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << " Элемент " << value << " добавлен в очередь.\n";
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << " Очередь пуста.\n";
        }
        else {
            Node* temp = front;
            front = front->next;
            std::cout << " Элемент " << temp->data << " удален из очереди.\n";
            delete temp;
        }
        count--;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            std::cout << " Очередь пуста.\n";
        }
        else {
            std::cout << " Элементы в очереди: ";
            Node* current = front;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    void size() const {
        std::cout << " Количество элементов в очереди: " << count <<"\n";
    }

    T& getRear() {
        if (rear == nullptr) {
            throw std::runtime_error(" Очередь пуста.\n");
        }
        std::cout << " Последний и наиболее недавно добавленный элемент в конец: " << rear->data << "\n";
        //return rear->data;
    }

    T& getFront() {
        if (front == nullptr) {
            throw std::runtime_error(" Очередь пуста.");
        }
        std::cout << " Первый элемент в начале: " << front->data << "\n";
        //return front->data;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    Queue<int> intQueue;
    Queue<std::string> stringQueue;

    int choice;
    do {
        std::cout << "\n Меню:\n";
        std::cout << " 1. Добавить элемент в очередь (целое число)\n";
        std::cout << " 2. Удалить элемент из очереди\n";
        std::cout << " 3. Отобразить элементы в очереди\n";
        std::cout << " 4. Количество элементов в очереди\n";
        std::cout << " 5. Возвращает ссылку на последний и наиболее недавно добавленный элемент в конец\n";
        std::cout << " 6. Вернуть ссылку на первый элемент в начале\n";
        std::cout << " 7. Выход\n";
        std::cout << " Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            std::cout << " Введите целое число для добавления в очередь: ";
            std::cin >> value;
            intQueue.enqueue(value);
            break;
        }
        case 2:
            intQueue.dequeue();
            break;
        case 3:
            intQueue.display();
            break;
        case 4:
            intQueue.size();
            break;
        case 5:
            intQueue.getRear();
            break;
        case 6:
            intQueue.getFront();
            break;
        case 7:
            std::cout << " Программа завершена.\n";
            break;
        default:
            std::cout << " Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 7);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
