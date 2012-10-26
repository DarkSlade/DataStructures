package com;

import com.Operator;
import com.Expression;
import com.Expression.WalkExecutor;
import com.WalkOrder;

public class CompoundExpression<T1,T2,T> implements Expression<T> {
  public Expression<T1> lExp;
  public Expression<T2> rExp;
  public Operator<T1, T2, T> optr;

  public CompoundExpression(){}

  public CompoundExpression(Expression<T1> lExp, Expression<T2> rExp, Operator<T1,T2,T> optr) {
    this.lExp = lExp;
    this.rExp = rExp;
    this.optr = optr;
  }

  @SuppressWarnings("unchecked")
  public T execute() {
    if (lExp == null || rExp == null) {
      if (lExp != null && optr == null) {
        return (T) lExp.execute();
      } 
      throw new IllegalStateException("Malformed compound expression");
    }
    return optr.operate(lExp.execute(), rExp.execute());
  }

  public void walkTree(WalkOrder order, WalkExecutor executor) {
    if (order == WalkOrder.PREORDER) {
      executor.execute(this);
    }
    if (lExp != null) {
      lExp.walkTree(order, executor);
    }
    if (order == WalkOrder.INORDER) {
      executor.execute(this);
    }
    if (rExp != null) {
      rExp.walkTree(order, executor);
    }
    if (order == WalkOrder.POSTORDER) {
      executor.execute(this);
    }
  }

  public String toString() {
    return optr != null ? optr.toString() : "NO OPERATOR";
  }

}

