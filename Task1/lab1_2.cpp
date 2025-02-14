#include <iostream>
using namespace std;

struct Node {
    std::string data;  // Данные узла
    Node* next;        // Указатель на следующий элемент
};

// Функция для проверки корректности ввода целого положительного числа
int getPositiveInteger() {
    int n;
    while (true) {
        std::cout << "Введите целое положительное число: ";
        std::cin >> n;

        if (n < 1 || n > 10) {
            std::cout << "Ошибка: число должно быть в диапазоне от 1 до 10\n";
        }

        if (std::cin.fail() || n <= 0) {
            std::cin.clear();  // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем ввод
            std::cout << "Ошибка: введите корректное целое положительное число.\n";
        } else {
            return n;
        }
    }
}

// Функция для проверки, содержит ли строка цифры
bool containsDigits(const std::string& str) {
    for (char c : str) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool containsInList(Node* head, const std::string& str) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == str) {
            return false;  // Строка найдена в списке
        }
        current = current->next;
    }
    return true;  // Строка не найдена
}

// Функция для получения строки, которая не содержит цифр
std::string getStringWithoutDigitsp(const std::string& prompt, Node* head) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (containsDigits(input)) {
            std::cout << "Ошибка: строка не должна содержать цифры. Попробуйте снова.\n";
        } else if (containsInList(head, input)) {
            std::cout << "Ошибка: такая строка не существует в списке. Попробуйте снова.\n";
        } else {
            return input;
        }
    }
}

std::string getStringWithoutDigits(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (containsDigits(input)) {
            std::cout << "Ошибка: строка не должна содержать цифры. Попробуйте снова.\n";
        } else {
            return input;
        }
    }
}

// Функция для формирования списка из n элементов
Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        Node* newNode = new Node();
        newNode->data = getStringWithoutDigits("Введите строку для элемента " + std::to_string(i + 1) + ": ");
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    return head;
}

// Функция для вставки элемента после элемента со значением X
void insertAfter(Node* head, const std::string& X, const std::string& newValue) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == X) {
            Node* newNode = new Node();
            newNode->data = newValue;
            newNode->next = current->next;
            current->next = newNode;
            std::cout << "Элемент " << newValue << " вставлен после " << X << ".\n";
        }
        current = current->next;
    }

    std::cout << "Элемент со значением " << X << " не найден в списке.\n";
}

// Функция для удаления первого элемента списка
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        std::cout << "Ошибка: список пуст.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    std::cout << "Первый элемент удалён.\n";
}

// Функция для смены местами первого и последнего элементов списка
void swapFirstAndLast(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "Ошибка: недостаточно элементов в списке для обмена.\n";
        return;
    }

    Node* first = head;
    Node* last = head;
    Node* prevLast = nullptr;

    while (last->next != nullptr) {
        prevLast = last;
        last = last->next;
    }

    if (first == last) {
        std::cout << "Ошибка: первый и последний элементы одинаковы.\n";
        return;
    }

    prevLast->next = first;
    last->next = first->next;
    first->next = nullptr;
    head = last;

    std::cout << "Первый и последний элементы поменялись местами.\n";
}

// Функция для вывода списка
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Список пуст.\n";
        return;
    }

    Node* current = head;
    std::cout << "Список: ";
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

// Очистка памяти
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int n;

    // Формирование списка
    n = getPositiveInteger();
    std::cin.ignore();  // Очищаем буфер после ввода числа
    head = createList(n);

    printList(head);

    // Вставка элемента после элемента со значением X
    std::string X =
        getStringWithoutDigitsp("Введите значение X, после которого нужно вставить новый элемент: ", head);
    std::string newValue = getStringWithoutDigits("Введите значение нового элемента: ");

    insertAfter(head, X, newValue);

    printList(head);

    // Удаление первого элемента
    deleteFirst(head);

    printList(head);

    // Смена местами первого и последнего элементов
    swapFirstAndLast(head);

    printList(head);

    // Освобождение памяти
    freeList(head);

    return 0;
}
