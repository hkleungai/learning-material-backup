datatype 'a ht = table of (int * ('a list)) list;
fun lookup key (table []) = []
  | lookup key (table (h::t)) = if key = #1(h) then #2(h)
                                else lookup key (table t);
(******************************************************************************)
fun exist (key, []) = false
  | exist (key, h::t) = if key = h then true
                        else exist(key, t);
fun ins (key, value) (table []) = [(key, [value])]
  | ins (key, value) (table (h::t)) = if key = #1(h) then if exist (value, #2(h)) then h::t
                                                             else (key, value::(#2(h)))::t
                                         else h:: (ins (key, value) (table t));
fun insert (key, value) (table t) = table (ins (key, value) (table t));
(******************************************************************************)
fun len ([]) = 0
  | len (h::t) = 1 + len(t);
fun valuecount (table []) = []
  | valuecount (table (h::t)) = (#1(h), len(#2(h)))::valuecount (table t);
(******************************************************************************)
fun insertval (x:int * int, []) = [x]
  | insertval (x:int * int, h::t) = if #2(x) > #2(h) then x::h::t
                                    else h::(insertval (x, t));
fun insertsort [] = []
  | insertsort (h::t) = insertval (h, insertsort t);
fun hotkeys t = insertsort (valuecount t);
(******************************************************************************)
fun kvs (key, []) = []
  | kvs (key, h::t) = if h > 0 then (key, h)::kvs(key, t)
                      else kvs(key, t);
fun positivekvs (table []) = []
  | positivekvs (table (h::t)) = kvs (#1(h), #2(h)) @ positivekvs (table t);
