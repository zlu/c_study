Great questions — let’s break it down clearly:

⸻

🧠 1. What is Standard C?

“Standard C” typically refers to the official versions of the C programming language defined by the ISO (International Organization for Standardization). These standards evolve over time to add features, fix problems, and modernize the language.

Each version has a name like C89, C99, C11, or C17.

⸻

📜 2. Major C Standards and Their Differences

🏛️ C89 / C90 (ANSI C)
	•	First standardized version (1989 ANSI, 1990 ISO)
	•	Basic features:
	•	int main(), #include, basic types, struct, pointers, etc.
	•	All declarations must come before code in a block
	•	Used in classic Unix and early Linux kernels

⸻

⚙️ C99 (ISO/IEC 9899:1999)

Introduced many modern features:

🔹 Key Features:
	•	// single-line comments
	•	inline functions
	•	long long data type (at least 64 bits)
	•	Variable declarations anywhere, not just at the top
	•	Variable-Length Arrays (VLA): e.g. int arr[n];
	•	stdbool.h: adds bool, true, false
	•	stdint.h: fixed-width types like int32_t, uint8_t

Adoption was slow initially due to compiler lag.

⸻

🧪 C11 (ISO/IEC 9899:2011)

Focused more on safety, multithreading, and standard libraries.

🔹 Key Features:
	•	_Atomic, <stdatomic.h> – thread-safe atomic operations
	•	_Thread_local – thread-local storage
	•	Anonymous structures/unions
	•	Bounds-checking functions (optional, like strcpy_s)
	•	Optional features for embedded and freestanding systems

⸻

🆕 C17 (ISO/IEC 9899:2018)
	•	Minor bugfix release — no major new features
	•	Clarifies ambiguities in C11

⸻

💻 3. What is cc on macOS?

🧩 cc is a compiler driver, not a language standard

On macOS:
	•	cc is usually a symbolic link to clang, Apple’s LLVM-based C compiler.
	•	You can verify with:

which cc
cc --version

You’ll likely see Apple clang version X.Y.Z.

⚙️ To control which C standard to use:

You can pass flags to cc:

C Standard	Command
C89	cc -std=c89
C99	cc -std=c99
C11	cc -std=c11
C17	cc -std=c17
Latest	cc -std=c2x (experimental)

Example:

cc -std=c99 -Wall -o myprog myprog.c

That tells clang (via cc) to compile using C99 rules and show warnings.

⸻

✅ Summary

Standard	Year	Key Additions
C89/C90	1989/1990	The original ANSI/ISO C
C99	1999	inline, // comments, VLAs, stdbool.h
C11	2011	Multithreading (_Atomic), safer libs
C17	2018	Bug fixes to C11
C2X	upcoming	Modernizations, still evolving

On macOS, cc is typically Clang, which supports all major C standards. Use -std=... to choose one.

⸻

Would you like to see examples of how code differs between C89, C99, and C11?
