# Open Close Principle

>  **Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification**

The general idea of this principle is great. It tells us to write our code so that we will be able to add new functionality without changing the existing code. That prevents situations in which a change to one of our classes also requires us to adapt all depending classes. Unfortunately, Bertrand Mayer proposes to use _inheritance_ to achieve this goal:

Inheritance introduces tight coupling if the subclasses depend on implementation details of their parent class.

That’s why Robert C. Martin and others redefined the Open/Closed Principle to the *Polymorphic* Open/Closed Principle. It uses interfaces instead of superclasses to allow different implementations which we can easily substitute without changing the code that uses them. The interfaces are closed for modifications, and we can provide new implementations to extend the functionality of our software.

The main benefit of this approach is that an interface introduces an additional level of abstraction which enables loose coupling. The implementations of an interface are independent of each other and don’t need to share any code. If we consider it beneficial that two implementations of an interface share some code, we can either use inheritance or composition.


Example :-)

Open chest surgery is not needed when putting on a coat.

<img src='OCP.jpg' width =300 height=300>


## References

1. [Stackify](https://stackify.com/solid-design-open-closed-principle/)