# auto in C++

Use `auto` when you want to work with a copy of elements in the range.
Use `auto&` when you want to modify elements in the range in non-generic code.
Use `auto&&` when you want to modify elements in the range in generic code.
Use `const auto&` when you want read-only access to elements in the range (even in generic code).

## Automatic Type Deduction

Variations:

- `auto`
- `const auto`
- `auto&`
- `const auto&`
- `auto&&`
- `const auto&&`
- `decltype(auto)`

## references:
1. [Variations of auto](https://blog.petrzemek.net/2016/08/17/auto-type-deduction-in-range-based-for-loops/)
2. [Universal References in C++11](https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers)