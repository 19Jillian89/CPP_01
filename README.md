# C++ Module 01 — Memory Allocation, References, Pointers to Members & Switch

> 42 School — C++ Module 01

---

## 🇬🇧 English

### About

This module introduces the core memory management and object-oriented concepts of C++, building on top of C knowledge. It covers four main pillars: **Stack vs Heap allocation**, **References**, **File & String Streams**, and **Pointers to Member Functions**.

---

### 🧠 Key Concepts

#### Stack vs Heap

In C++, memory is divided into two main areas:

- **Stack** — automatic, fast, limited. Variables live here by default and are destroyed automatically when their scope ends.
- **Heap** — manual, flexible, large. Memory is allocated with `new` and must be freed with `delete`.

```cpp
// Stack — destroyed automatically at end of scope
Zombie z("Bob");

// Heap — you control when it's destroyed
Zombie* z = new Zombie("Bob");
delete z; // mandatory!
```

The key rule: every `new` must have a `delete`, every `new[]` must have a `delete[]`.

---

#### References (`&`)

A reference is an **alias** — another name for the same variable. It shares the exact same memory address as the original.

```cpp
std::string name = "Alice";
std::string& ref = name;   // ref IS name — same address

ref = "Bob";
std::cout << name;  // prints "Bob"
```

Key rules:
- Must be initialized immediately — cannot exist uninitialized
- Cannot be `NULL`
- Cannot change what it refers to after initialization

Compared to pointers:

| | Pointer `*` | Reference `&` |
|---|---|---|
| Can be NULL | ✅ | ❌ |
| Must be initialized | ❌ | ✅ |
| Can change target | ✅ | ❌ |
| Syntax | `*ptr` / `ptr->` | direct |

---

#### File & String Streams

C++ replaces C file functions (`fopen`, `fprintf`) with stream objects:

```cpp
std::ifstream infile("input.txt");   // read from file
std::ofstream outfile("output.txt"); // write to file

std::string line;
while (std::getline(infile, line)) {
    outfile << line << "\n";
}

infile.close();
outfile.close();
```

Useful `std::string` methods:
- `find(s)` — returns position of `s`, or `std::string::npos` if not found
- `substr(pos, len)` — extracts a substring
- `length()` — returns string length
- `empty()` — returns true if string is empty

---

#### Pointers to Member Functions

In C++, methods belong to a class and implicitly receive `this`. You cannot use a plain C function pointer for them — you need a **pointer to member function**:

```cpp
void (Harl::*func)() = &Harl::debug;  // store which method to call

Harl h;
(h.*func)();   // call debug() on object h
```

Combined with a parallel array, this replaces long `if/else` chains:

```cpp
void (Harl::*funcs[4])() = {
    &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
};
std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

for (int i = 0; i < 4; i++)
    if (levels[i] == level)
        { (this->*funcs[i])(); return; }
```

---

### 📁 Exercises

#### ex00 — BraiiiiiiinnnzzzZ
**Topic:** Stack vs Heap allocation

Creates a `Zombie` class and demonstrates the difference between stack and heap allocation through two functions:
- `randomChump()` — allocates on the **stack**, zombie is destroyed automatically at end of scope
- `newZombie()` — allocates on the **heap** with `new`, zombie survives the function and must be manually deleted

#### ex01 — Moar brainz!
**Topic:** Array allocation with `new[]`

Implements `zombieHorde()` which allocates N zombies in a **single allocation** using `new[]`. Demonstrates that `delete[]` must be used (not `delete`) to properly destroy all objects and avoid memory leaks.

#### ex02 — HI THIS IS BRAIN
**Topic:** Demystifying references

Prints the memory address and value of a string, a pointer to it, and a reference to it. The key insight: all three addresses are **identical** — a reference is not magic, it is simply another name for the same memory location.

#### ex03 — Unnecessary violence
**Topic:** References vs pointers as class members

Implements `Weapon`, `HumanA`, and `HumanB` classes to demonstrate when to use a reference vs a pointer as a class member:
- `HumanA` uses `Weapon&` — always armed, reference set in constructor, cannot be NULL
- `HumanB` uses `Weapon*` — may be unarmed, pointer can be `NULL`, set later via `setWeapon()`

#### ex04 — Sed is for losers
**Topic:** File I/O and string manipulation

Recreates the Unix `sed` substitution command in C++. Opens a file, replaces every occurrence of `s1` with `s2`, and writes the result to `<filename>.replace`. Uses `std::ifstream`, `std::ofstream`, `std::string::find()`, and `std::string::substr()`. `std::string::replace` is forbidden.

#### ex05 — Harl 2.0
**Topic:** Pointers to member functions

Implements a `Harl` class that complains at four log levels (DEBUG, INFO, WARNING, ERROR). Uses an **array of pointers to member functions** to dispatch the correct method without any `if/else` chain.

#### ex06 — Harl filter
**Topic:** Switch statement and fall-through

Filters Harl's complaints from a given level upward. Uses a `switch` statement **without `break`** between cases, intentionally exploiting **fall-through** as a filter mechanism.

---

## 🇮🇹 Italiano

### Di cosa tratta

Questo modulo introduce i concetti fondamentali di gestione della memoria e di programmazione orientata agli oggetti in C++, partendo dalla base del C. Copre quattro pilastri principali: **Stack vs Heap**, **Riferimenti**, **File & String Streams**, e **Puntatori a Funzioni Membro**.

---

### 🧠 Concetti Chiave

#### Stack vs Heap

In C++ la memoria è divisa in due zone principali:

- **Stack** — automatico, veloce, limitato. Le variabili vivono qui di default e vengono distrutte automaticamente quando il loro scope termina.
- **Heap** — manuale, flessibile, grande. La memoria viene allocata con `new` e deve essere liberata con `delete`.

```cpp
// Stack — distrutto automaticamente a fine scope
Zombie z("Bob");

// Heap — sei tu a decidere quando distruggerlo
Zombie* z = new Zombie("Bob");
delete z; // obbligatorio!
```

La regola fondamentale: ogni `new` deve avere il suo `delete`, ogni `new[]` deve avere il suo `delete[]`.

---

#### Riferimenti (`&`)

Un riferimento è un **alias** — un altro nome per la stessa variabile. Condivide esattamente lo stesso indirizzo di memoria della variabile originale.

```cpp
std::string name = "Alice";
std::string& ref = name;   // ref È name — stesso indirizzo

ref = "Bob";
std::cout << name;  // stampa "Bob"
```

Regole fondamentali:
- Deve essere inizializzato subito — non può esistere non inizializzato
- Non può essere `NULL`
- Non può cambiare a cosa si riferisce dopo l'inizializzazione

Confronto con i puntatori:

| | Puntatore `*` | Reference `&` |
|---|---|---|
| Può essere NULL | ✅ | ❌ |
| Deve essere inizializzato | ❌ | ✅ |
| Può cambiare target | ✅ | ❌ |
| Sintassi accesso | `*ptr` / `ptr->` | diretta |

---

#### File & String Streams

Il C++ sostituisce le funzioni C per i file (`fopen`, `fprintf`) con oggetti stream:

```cpp
std::ifstream infile("input.txt");   // leggi da file
std::ofstream outfile("output.txt"); // scrivi su file

std::string line;
while (std::getline(infile, line)) {
    outfile << line << "\n";
}

infile.close();
outfile.close();
```

Metodi utili di `std::string`:
- `find(s)` — restituisce la posizione di `s`, oppure `std::string::npos` se non trovato
- `substr(pos, len)` — estrae una sottostringa
- `length()` — lunghezza della stringa
- `empty()` — true se la stringa è vuota

---

#### Puntatori a Funzioni Membro

In C++ i metodi appartengono a una classe e ricevono implicitamente `this`. Non puoi usare un puntatore a funzione del C — hai bisogno di un **puntatore a funzione membro**:

```cpp
void (Harl::*func)() = &Harl::debug;  // salvo quale metodo chiamare

Harl h;
(h.*func)();   // chiamo debug() sull'oggetto h
```

Combinato con un array parallelo, sostituisce le lunghe catene di `if/else`:

```cpp
void (Harl::*funcs[4])() = {
    &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
};
std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

for (int i = 0; i < 4; i++)
    if (levels[i] == level)
        { (this->*funcs[i])(); return; }
```

---

### 📁 Esercizi

#### ex00 — BraiiiiiiinnnzzzZ
**Argomento:** Stack vs Heap

Crea la classe `Zombie` e dimostra la differenza tra allocazione su stack e heap tramite due funzioni:
- `randomChump()` — alloca sullo **stack**, lo zombie viene distrutto automaticamente a fine scope
- `newZombie()` — alloca sull'**heap** con `new`, lo zombie sopravvive alla funzione e va eliminato manualmente con `delete`

#### ex01 — Moar brainz!
**Argomento:** Array con `new[]`

Implementa `zombieHorde()` che alloca N zombie in una **singola allocazione** con `new[]`. Dimostra che bisogna usare `delete[]` (non `delete`) per distruggere correttamente tutti gli oggetti ed evitare memory leak.

#### ex02 — HI THIS IS BRAIN
**Argomento:** Demistificare i riferimenti

Stampa l'indirizzo e il valore di una stringa, del suo puntatore e del suo riferimento. Il punto chiave: tutti e tre gli indirizzi sono **identici** — un riferimento non è magia, è semplicemente un altro nome per la stessa zona di memoria.

#### ex03 — Unnecessary violence
**Argomento:** Reference vs puntatore come membri di classe

Implementa le classi `Weapon`, `HumanA` e `HumanB` per dimostrare quando usare una reference o un puntatore come attributo di classe:
- `HumanA` usa `Weapon&` — sempre armato, reference inizializzata nel costruttore, non può essere NULL
- `HumanB` usa `Weapon*` — può essere disarmato, il puntatore può essere `NULL`, viene impostato dopo con `setWeapon()`

#### ex04 — Sed is for losers
**Argomento:** File I/O e manipolazione stringhe

Ricrea il comando Unix `sed` in C++. Apre un file, sostituisce ogni occorrenza di `s1` con `s2` e scrive il risultato in `<filename>.replace`. Usa `std::ifstream`, `std::ofstream`, `std::string::find()` e `std::string::substr()`. `std::string::replace` è vietato.

#### ex05 — Harl 2.0
**Argomento:** Puntatori a funzioni membro

Implementa la classe `Harl` che si lamenta su quattro livelli di log (DEBUG, INFO, WARNING, ERROR). Usa un **array di puntatori a funzioni membro** per chiamare il metodo corretto senza nessuna catena di `if/else`.

#### ex06 — Harl filter
**Argomento:** Switch statement e fall-through

Filtra i messaggi di Harl dal livello scelto in su. Usa uno `switch` **senza `break`** tra i casi, sfruttando intenzionalmente il **fall-through** come meccanismo di filtro.

---

*42 Roma Elis — C++ Modules*
