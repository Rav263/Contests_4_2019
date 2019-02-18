int main() {
    int count;
    std::cin >> count;

    Holder *elements = new Holder[count];

    for (int i = 0; i < count / 2; i++) {
        elements[i].swap(elements[count - i - 1]);
    }

    delete[] elements;
}
