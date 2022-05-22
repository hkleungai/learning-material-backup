;Input code:
;
;object L {
;  abstract class List
;  case class Nil() extends List
;  case class Cons(h: Int, t: List) extends List
;
; def concat(l1: List, l2: List): List = {
;    l1 match {
;      case Nil() => l2
;      case Cons(h, t) => Cons(h, concat(t, l2))
;    }
;  }
;}

; Headers are omitted

(func $L_concat (param i32 i32) (result i32) (local i32 i32 i32 i32 i32 i32)
  get_local 0
  set_local 2       ; local_2 <- l1 
  get_local 2
  set_local 7       ; local_7 <- l1. Nobody said the code is efficient!
  get_local 7       ; stack: l1
  i32.load          ; stack: constructor(l1)
  i32.const 0       
  i32.eq            ; stack: constructor(l1) == 0 (Nil)
  if (result i32)   
    i32.const 1
  else
    i32.const 0
  end               ; stack: pattern Nil() matched. Nil has no fields, so this if does nothing
  if (result i32)   
    get_local 1     ; stack: l2 (and function returns)
  else
    get_local 2     ; stack: l1
    set_local 5
    get_local 5     ; stack: l1
    i32.load        ; stack: constructor(l1)
    i32.const 1     
    i32.eq          ; stack: constructor(l1) == 1 (Cons)
    if (result i32) 
      get_local 5   ; stack: l1
      i32.const 4   
      i32.add       ; stack: (l1 + 4), i.e. pointer to h
      i32.load      ; stack: h
      set_local 3   ; local_3 = h
      i32.const 1   ; stack: h matches (always true)
      get_local 5   ; stack: h matches, l1
      i32.const 8 
      i32.add       ; stack: h matches, pointer to t
      i32.load      ; stack: h matches, t
      set_local 4   ; local_4 = t. stack: h matches
      i32.const 1   ; stack: h matches, t matches
      i32.and
    else
      i32.const 0
    end             ; stack: pattern Cons(h, t) matched
    if (result i32)
      get_global 0  ; stack: memboundary
      set_local 6   ; local_6 = memboundary
      get_global 0  ; stack: memboundary
      i32.const 12
      i32.add
      set_global 0  ; increase it by 12, i.e. constructor id for cons + 2 fields
      get_local 6   ; stack: old memboundary, i.e. where we will allocate Cons(h, concat(t, l2))...
      i32.const 1   ;     let's call this address base
      i32.store     ; store 1 (aka. Cons) to base
      get_local 6   ; stack: base
      i32.const 4
      i32.add       ; stack: base + 4
      get_local 3   ; stack: base + 4, h
      i32.store     ; store h to (base + 4)
      get_local 6   ; stack: base
      i32.const 8   
      i32.add       ; stack: base + 8
      get_local 4   ; stack: base + 8, t
      get_local 1   ; stack: base + 8, t, l2
      call $L_concat ; stack: base + 8, L_concat(t, l2)
      i32.store     ; store L_concat(t, l2) to (base + 8)
      get_local 6   ; stack: base (and function returns)
    else
      get_global 0  ; All this code is just allocating an error message to memory...
      i32.const 0
      i32.add
      i32.const 77
      i32.store8
      get_global 0
      i32.const 1
      i32.add
      i32.const 97
      i32.store8
      get_global 0
      i32.const 2
      i32.add
      i32.const 116
      i32.store8
      get_global 0
      i32.const 3
      i32.add
      i32.const 99
      i32.store8
      get_global 0
      i32.const 4
      i32.add
      i32.const 104
      i32.store8
      get_global 0
      i32.const 5
      i32.add
      i32.const 32
      i32.store8
      get_global 0
      i32.const 6
      i32.add
      i32.const 101
      i32.store8
      get_global 0
      i32.const 7
      i32.add
      i32.const 114
      i32.store8
      get_global 0
      i32.const 8
      i32.add
      i32.const 114
      i32.store8
      get_global 0
      i32.const 9
      i32.add
      i32.const 111
      i32.store8
      get_global 0
      i32.const 10
      i32.add
      i32.const 114
      i32.store8
      get_global 0
      i32.const 11
      i32.add
      i32.const 33
      i32.store8
      get_global 0
      i32.const 12
      i32.add
      i32.const 0
      i32.store8
      get_global 0
      i32.const 13
      i32.add
      i32.const 0
      i32.store8
      get_global 0
      i32.const 14
      i32.add
      i32.const 0
      i32.store8
      get_global 0
      i32.const 15
      i32.add
      i32.const 0
      i32.store8
      get_global 0
      get_global 0
      i32.const 16
      i32.add
      set_global 0   ; until here! stack: error msg
      call $Std_printString
      unreachable    ; fail execution!
    end
  end
)
