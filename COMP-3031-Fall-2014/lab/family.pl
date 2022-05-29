parent('John', 'James').% fact
parent('John', 'Mary'). % fact
parent('James', 'Judy'). % fact

age('John',60). % fact
age('James',35). % fact
age('Mary',30). % fact
age('Judy',9). % fact

male('John'). % fact
male('James'). % fact
female('Mary'). % fact
female('Judy'). % fact

sibling(X, Y) :- parent(_1,X), parent(_1,Y).      % rule
ancestor(X, Y) :- parent(X, Y).                   % rule
ancestor(X, Y) :- parent(_1, Y), ancestor(X, _1). % rule
