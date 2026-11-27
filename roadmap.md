Here's the full journey, one project per folder in your `systems-from-scratch` repo.

## Phase 0: Setup ✅
**00-setup**: WSL, gcc, gdb, Git, your first C program.
*Learned:* variables are bytes at addresses, stack, garbage values, little-endian, ASLR, debug info.

## Phase 1: How a CPU runs code
**01-chip8-emulator**: a software CPU that runs real old games.
*Learn:* the fetch–decode–execute loop, registers, program counter, call stack, machine code as bytes, bit manipulation.

## Phase 2: Memory
**02-malloc**: your own `malloc()` and `free()`.
*Learn:* how the heap works, how memory is requested from the OS, block headers, free lists, fragmentation, and why memory bugs (use-after-free, overflows) happen.

**03-page-tables**: a simulator that translates virtual addresses to physical ones.
*Learn:* virtual memory, pages, multi-level page tables, the TLB cache, page faults, and how every process gets its own private memory.

## Phase 3: Processes
**04-shell**: your own mini terminal that runs commands, pipes (`|`) and redirection (`>`).
*Learn:* what a process is, `fork`/`exec`/`wait`, system calls, file descriptors, and what actually happens when you run a program.

**05-threads**: your own thread library, switching between tasks yourself.
*Learn:* context switching (saving and restoring registers), scheduling, and how one CPU runs many things "at once."

## Phase 4: Concurrency and parallelism
**06-concurrency**: break a shared counter, then build your own locks, a producer–consumer queue and a thread pool.
*Learn:* race conditions, atomic instructions, mutexes, spinlocks, deadlocks, condition variables.

**07-parallel-matmul**: matrix multiplication, single-threaded → multi-threaded → cache-optimized, with benchmarks.
*Learn:* how multiple cores really work, CPU caches, why memory layout matters for speed, and the core math behind AI workloads.

## Phase 5: The kernel
**08-mini-kernel**: your own small OS kernel booting in QEMU (RISC-V).
*Learn:* booting with no OS underneath, interrupts, a kernel memory allocator, a scheduler, and user mode vs kernel mode. All the earlier projects come together here.

## Optional capstone
**09-tiny-inference-engine**: run a small AI language model on the CPU in C.
*Learn:* how everything above (memory, threads, cache, parallel math) powers real AI.

---

Back to where we paused: answer the **4 check questions** from Step 1 (PC, decode `0x7A03`, where the return address goes, the `0x12 0x34` instruction), then we'll start Step 2. Want this list saved as a doc so you can tick projects off as you go?