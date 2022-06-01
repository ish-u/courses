% 4. Write a program in PROLOG to implement generate_fib(N,T) where T represents the
% Nth term of the fibonacci series.
% base case
generate_fib(0, 1) :- !.
generate_fib(1, 1) :- !.
% recursive case
generate_fib(N, T) :-
    N>0,
    N>1,
    N1 is N-1,
    N0 is N-2,
    generate_fib(N0, T0),
    generate_fib(N1, T1),
    T is T0+T1.

print_fib(N) :-
    N> -1,
    generate_fib(N, T),
    write(T),
    write("\t"),
    N1 is N-1,
    print_fib(N1).

