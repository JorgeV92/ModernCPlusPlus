# Smart Pointers 

`C++`, `std::shared_ptr` and `std::unique` are two types of smart pointers provided by Standard Library.
They help manage dynamic memory by automatically deallocating memeory when it is no longer needed. 

## `std::shared_ptr`

`std::shared_ptr` is a smart pointer that maintains reference counting. It allows multiple shared pointers to own 
the same resource, and the resource is deallocated only when the last `std::shared_ptr` owning the resource is 
destroyed.

### Key features:
1. **Reference Counting:** It keeps track of how many `std::shared_ptr` instances share the same ressource. When the last
     `std::shared_ptr` to the resource is destroyed, the resouce itself is deallocated.
2. **Copyable and Assignable:** You can copy and assign `std::shared_ptr` instances, which increments the reference count.
3. **Thread-Safe:** The reference counting mechanism is thread-safe.

```cpp
void useShared() {
  // Create a shared_ptr managing a new int
  std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
  {
    // Create anothe shated_ptr managing the same int
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "Insiade block: " << *ptr2 << std::endl; 
  }
  // The resource is still available via ptr1
  std::cout << "Outside block: " << *ptr1 << std::endl;
  // When ptr1 goes out of scope, the resource is deallocated 
}
```

## `std::unique_ptr`

`std::unique_ptr` is a smart pointer that exclusively owns a resource. It ensures that the resource is owned by only one 
`std::unique_ptr` at a time.

### Key Features:
1. **Exclusive Ownership:** Only one std::unique_ptr can own a resource at a time. Ownership can be transferred using std::move, but copying is not allowed.
2. **Non-Copyable:** You cannot copy std::unique_ptr instances, ensuring that the resource has a single owner.
3. **Efficient:** Because there is no reference counting overhead, std::unique_ptr is more efficient than std::shared_ptr.


```cpp
void useUnique() {
    // Create a unique_ptr managing a new int
    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
    std::cout << "ptr1: " << *ptr1 << std::endl;

    // Transfer ownership to ptr2 using std::move
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    std::cout << "ptr2: " << *ptr2 << std::endl;

    // ptr1 is now empty, as ownership has been transferred
    if (!ptr1) {
        std::cout << "ptr1 is empty" << std::endl;
    }

    // When ptr2 goes out of scope, the resource is deallocated
}
```
## When to Use `std::shared_ptr` vs `std::unique_ptr`

- Use `std::shared_ptr` when you need shared ownership of a resource. This is common when multiple objects need access to the same resource, and the resource should only be deallocated when all owners are done using it.
- Use `std::unique_ptr` when you want exclusive ownership of a resource. This is typical when the resource is owned by a single object or when ownership can be transferred but not shared.
