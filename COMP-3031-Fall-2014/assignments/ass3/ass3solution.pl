%%%%%%%%%% Q1
listmirror([], []) :- !.
listmirror(X, L):-reverse(X, L1), append(X, L1, L), !.

%%%%%%%%%% Q2
listdiff([],_,[]).
listdiff([H|T],X,Y):-member(H,X), !, listdiff(T,X,Y).
listdiff([H|T],X,[H|Y]):-listdiff(T,X,Y).

%%%%%%%%%% Q3
insert(X,[],[X]):-!.
insert(X,[H|T],[X,H|T]):-H>=X,!.
insert(X,[H|T],[H|Y]):-insert(X,T,Y).

%%%%%%%%%% Q4
bit(0).
bit(1).
bitsgen(0, []) :- !.
bitsgen(X, [H|L]):- X > 0, bit(H), X1 is X - 1, bitsgen(X1, L).

%%%%%%%%%% Q5
checktree(nil).
checktree(t(X, L, R)):-checktree(L), checktree(R).

preorder(nil,[]).
preorder(t(X,L,R),[X|T]) :- preorder(L,LL),preorder(R,LR),append(LL,LR,T).

