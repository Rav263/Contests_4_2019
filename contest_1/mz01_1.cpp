struct Sum
{
    int a;
    int b;

    Sum(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int get(void) const {
        return this->a + this->b;
    }
    Sum(const Sum &a, int b) {
        this->a = a.get();
        this->b = b;
    } 
};
