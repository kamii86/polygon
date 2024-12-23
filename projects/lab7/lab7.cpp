#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Класс для решения задачи
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        // Определяем размер массива nums
        const int n = nums.size();

        // Создаем массив индексов от 0 до n-1
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }

        // Сортируем индексы по значению nums[ind[x]]
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return nums[x] < nums[y];
        });

        // `m` — текущая длина массива, которая будет уменьшаться
        int m = n;

        // `r` — общее количество операций
        long long r = 0;

        // Обрабатываем массив отсортированных индексов
        for (int i = 1; i < n; ++i) {
            // Если текущий индекс меньше предыдущего (индексы "перепрыгнули" в начало массива)
            if (ind[i] < ind[i - 1]) {
                // Добавляем текущую длину массива к результату
                r += m;
                // Обновляем текущую длину массива
                m = n - i;
            }
        }

        // Добавляем операции для удаления оставшихся элементов
        r += m;

        // Возвращаем общее количество операций
        return r;
    }
};
