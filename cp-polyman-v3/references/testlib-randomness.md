# testlib Randomness for Generators

All randomness in Polyman V3 generators must use `testlib.h` unless explicitly overridden.

## Pattern

```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");  // Read -n parameter
    int seed = opt<int>("seed");  // Read -seed parameter
    
    // Use rnd for all randomness
    for (int i = 0; i < n; i++) {
        int x = rnd.next(1, 1000000);  // uniform [1, 1000000]
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
```

## testlib Random Functions

- `rnd.next(n)` — uniform [0, n-1]
- `rnd.next(l, r)` — uniform [l, r]
- `rnd.wnext(n, t)` — weighted toward smaller values (t > 0) or larger (t < 0)
- `rnd.any(container)` — random element
- `shuffle(begin, end)` — shuffle using rnd

## Don't Use

- `rand()`, `srand()`
- `<random>` library
- `time(nullptr)` for seeding
- Platform-specific RNG

## Why

- Deterministic replay across platforms
- Polygon requires testlib randomness
- `-seed` parameter enables reproducibility
- Consistent with Polygon/Codeforces standards

## Seed Management

Pass seed via command-line argument:

```bash
gen-random -n 100 -seed 42
```

In generator script:
```freemarker
<#list 1..10 as i>
gen-random -n 100 -seed ${i} > $
</#list>
```

This ensures every test is deterministically reproducible.
