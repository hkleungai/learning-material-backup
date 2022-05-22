package amyc.ast

import amyc.utils.Positioned

// Definitions of symbolic Amy syntax trees
trait TreeModule {
  // Common ancestor for all trees
  trait Tree extends Positioned

  // Expressions
  trait Expr extends Tree

  // Variables
  case class Variable(name: Identifier) extends Expr

  // Literals
  trait Literal[+T] extends Expr { val value: T }
  case class IntLiteral(value: Int) extends Literal[Int]
  case class BooleanLiteral(value: Boolean) extends Literal[Boolean]
  case class StringLiteral(value: String) extends Literal[String]
  case class UnitLiteral() extends Literal[Unit] { val value: Unit = () }

  // Binary operators
  case class Plus(lhs: Expr, rhs: Expr) extends Expr
  case class Minus(lhs: Expr, rhs: Expr) extends Expr
  case class Times(lhs: Expr, rhs: Expr) extends Expr
  case class Div(lhs: Expr, rhs: Expr) extends Expr
  case class Mod(lhs: Expr, rhs: Expr) extends Expr
  case class LessThan(lhs: Expr, rhs: Expr) extends Expr
  case class LessEquals(lhs: Expr, rhs: Expr) extends Expr
  case class And(lhs: Expr, rhs: Expr) extends Expr
  case class Or(lhs: Expr, rhs: Expr) extends Expr
  case class Equals(lhs: Expr, rhs: Expr) extends Expr
  case class Concat(lhs: Expr, rhs: Expr) extends Expr

  // Unary operators
  case class Not(e: Expr) extends Expr
  case class Neg(e: Expr) extends Expr

  // Function/ type constructor call
  case class Call(qname: Identifier, args: List[Expr]) extends Expr
  // The ; operator
  case class Sequence(e1: Expr, e2: Expr) extends Expr
  // Local variable definition
  case class Let(df: ParamDef, value: Expr, body: Expr) extends Expr
  // If-then-else
  case class Ite(cond: Expr, thenn: Expr, elze: Expr) extends Expr
  // Pattern matching
  case class Match(scrut: Expr, cases: List[MatchCase]) extends Expr {
    require(cases.nonEmpty)
  }
  // Represents a computational error; prints its message, then exits
  case class Error(msg: Expr) extends Expr

  // Cases and patterns for Match expressions
  case class MatchCase(pat: Pattern, expr: Expr) extends Tree

  abstract class Pattern extends Tree
  case class WildcardPattern() extends Pattern // _
  case class IdPattern(name: Identifier) extends Pattern // x
  case class LiteralPattern[+T](lit: Literal[T]) extends Pattern // 42, true
  case class CaseClassPattern(constr: Identifier, args: List[Pattern]) extends Pattern // C(arg1, arg2)

  // Definitions
  trait Definition extends Tree { val name: Identifier }
  case class ModuleDef(name: Identifier, defs: List[ClassOrFunDef], optExpr: Option[Expr]) extends Definition
  trait ClassOrFunDef extends Definition
  case class FunDef(name: Identifier, params: List[ParamDef], retType: TypeTree, body: Expr) extends ClassOrFunDef {
    def paramNames = params.map(_.name)
  }
  case class AbstractClassDef(name: Identifier) extends ClassOrFunDef
  case class CaseClassDef(name: Identifier, fields: List[TypeTree], parent: Identifier) extends ClassOrFunDef
  case class ParamDef(name: Identifier, tpe: TypeTree) extends Definition

  // Types
  trait Type
  case object IntType extends Type 
  case object BooleanType extends Type
  case object StringType extends Type
  case object UnitType extends Type
  case class ClassType(qname: Identifier) extends Type

  // A wrapper for types that is also a Tree (i.e. has a position)
  case class TypeTree(tpe: Type) extends Tree

  // All is wrapped in a program
  case class Program(modules: List[ModuleDef]) extends Tree
}

// Identifiers represent unique names in Amy
class Identifier private(val name: String)
