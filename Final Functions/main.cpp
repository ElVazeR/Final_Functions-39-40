#include <iostream>
#include <cstdlib>
#include <ctime>

// Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;

}

// Вывод массива в консоль 
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length;i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

// Задача 1.
void type_of(int num1) { std::cout << "INT\n"; }
void type_of(double num1) { std::cout << "Double\n"; }
void type_of(float num1) { std::cout << "Float\n"; }


// Прототип функции - объявление функции без определения её тела с целью предоставления компилятору основной информации о её существование.
int range_sum(int left, int right);

//Задача 3.
template <typename T>
void middle_sort(T arr[], const int length);

//Задача 4.
template <typename T>
void move_arr(T arr[], const int length, int steps);

int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;

	// Задача 1. Вывести тип числа.
	std::cout << "Задча 1.\n";
	std::cout << "5   - "; type_of(5);
	std::cout << "5.  - "; type_of(5.);
	std::cout << "5.f - "; type_of(5.f); // f - это тип данных float.
	std::cout << std::endl;

	// Задача 2. Рекурсивная сумма диапазона
	std::cout << "Задача 2. \nВведите начало диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	std::cout << "Сумма чисел из диапазона = " << range_sum(n, m);

	// Задача 3. Сортировка середины.
	std::cout << "задча 3.\n Изначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);

	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);

	// Задача 4. Сдвиг массива по кругу.
	std::cout << "Задача 4.\nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print_arr(arr4, size4);
	std::cout << "Введите количество сдвигов -> ";
	std::cin >> n;
	
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);

	return 0;
}
// Прототип функции.
int range_sum(int left, int right) {
	if (left > right)
		std::swap(left, right); // Поменяли местами 8 и 5. Либо пишем -> throw "Ошибка!!!!!";
	if (left == right) // Условие выхода из рекурсии.
		return left;
	return range_sum(left, right - 1) + right;
}
template <typename T>

// Задача 3.
void middle_sort(T arr[], const int length) {
	int first_negative = -1, last_negative = -1;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_negative = i;
			break;
		}
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			last_negative = i;
			break;
		}
	// Сортировка 
	
	for (int i = last_negative - 1; i > first_negative + 1; i--) // Пузырьковая сортировка.
		for (int j = first_negative + 1; j < i; j++) 
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}
// Задача 4.
template <typename T>
void move_arr(T arr[], const int length, int steps) {
	for (int j = 0; j < steps; j++) {
		T tmp = arr[length - 1];
		for (int i = length - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = tmp;
	}
}