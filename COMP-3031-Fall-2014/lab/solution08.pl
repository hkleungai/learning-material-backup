%reverse
reverse([],L) :- append([],[],L).
reverse([H|T],L) :- reverse(T,L1),append(L1,[H],L).

%prefix
%base case
prefix([],_).
%inductive case
prefix([X|Xs],[X|Ys]) :- prefix(Xs,Ys).
