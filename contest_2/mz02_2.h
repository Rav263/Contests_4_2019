#include "mz02_1.h"

namespace numbers 
{
    class complex_stack 
    {
    private:
        size_t cappa = 0;
        size_t length = 4;
        size_t modifier = 2;

        complex *stack = nullptr;
        
        void extend_memmory(void) {
            length *= modifier;
            complex *new_stack = new complex[length];
            
            for(size_t i = 0; i < cappa; i++) {
                new_stack[i] = stack[i];
            }

            delete[] stack;
            stack = new_stack;
        }

    public:

        complex_stack() {
            stack = new complex[length];
        }

        ~complex_stack() {
            delete[] stack;
        }

        size_t size(void) const {
            return cappa;
        }
        
        complex &operator[](size_t index) const {
            return stack[index];
        }

        complex_stack(const complex_stack &now) {
            this->length = now.length;
            this->cappa = now.cappa;

            this->stack = new complex[length];
        
            for (size_t i = 0; i < this->cappa; i++) {
                this->stack[i] = now.stack[i];
            }
        }

        complex_stack operator=(const complex_stack &now) {
            if (this != &now) {
                delete[] this->stack;
                this->cappa = now.cappa;
                this->length = now.length;

                this->stack = new complex[this->length];
                
                for (size_t i = 0; i < this->cappa; i++) {
                    this->stack[i] = now.stack[i];
                }
            }

            return *this;
        }

        complex_stack operator<<(complex additional) const{
            complex_stack new_stack = *this;

            if (new_stack.cappa == new_stack.length) {
                new_stack.extend_memmory();
            }
            new_stack.stack[new_stack.cappa] = additional;
            new_stack.cappa += 1;
            
            return new_stack;
        }

        complex &operator+(void) const {
            return this->stack[this->cappa - 1];
        }

        complex_stack operator~(void) const {
            complex_stack new_stack = *this;

            new_stack.cappa -= 1;
            new_stack.stack[new_stack.cappa] = 0;

            return new_stack;
        }
    };
}
