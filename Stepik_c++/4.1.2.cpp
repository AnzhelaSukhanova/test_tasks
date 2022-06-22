#include <iostream>

struct Foo
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

struct FooHeir : Foo
{
	FooHeir(const char *msg) : Foo(msg) { }
};

void foo_says(const Foo &foo) { foo.say(); }


FooHeir get_foo(const char *msg) {
	return FooHeir(msg);
}

int main()
{
	foo_says(get_foo("Hello!"));
}
