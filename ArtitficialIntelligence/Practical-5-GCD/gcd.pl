% 5. Write a Prolog program to implement GCD of two numbers.
gcd(X, Y) :-
    (   X==0
    ->  write(Y)
    ;   Y==0
    ->  write(X)
    ;   X==Y
    ->  write(X)
    ;   X>Y
    ->  Z is X-Y,
        gcd(Z, Y)
    ;   X<Y
    ->  Z is Y-X,
        gcd(Y, Z)
    ).
