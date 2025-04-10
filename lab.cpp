#include <iostream>
#include <string>

using namespace std;

class vect {
    int dim;
    double* v;
    int num;
    static int count;
public:
    vect();
    vect(int n, double* x);
    vect(int n);
    vect(vect &x);
    ~vect();
    void print();
};

int vect::count = 0;

vect :: vect(vect &x) {
    count ++; 
    num = count;
    cout << "Конструктор ... создал вектор № " << num << endl;
    dim = x.dim;
    v = new double[dim];
    for (int i = 0; i < dim; i++) v[i] = x.v[i];
}

vect :: ~vect() {
    cout << "Удален вектор № " << num << endl;
    if (dim != NULL) delete[] v;
}

vect :: vect(int n, double* x) { //не поняла
    count++;
    num = count;
    dim = n;
    v = new double[dim];
    for (int i = 0; i < dim; i++) v[i] = x[i];
}


void vect :: print() {
    cout << "Вектор №" << num << ": ";
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 5;
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Создание вектора с инициализацией
    vect v1(size, values);
    v1.print();

    // Создание копии вектора
    vect v2(v1);
    v2.print();

    return 0;
}
