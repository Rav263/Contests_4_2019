class Sum
{
private:
    int a;
    int b;
public:
    Sum(int a, int b) : a(a), b(b) {}
    
    int get(void) const {
        return this->a + this->b;
    }
    Sum(const Sum &a, int b) : b(b) {
        this->a = a.get();
    } 
};
