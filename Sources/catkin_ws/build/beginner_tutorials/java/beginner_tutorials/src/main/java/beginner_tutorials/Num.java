package beginner_tutorials;

public interface Num extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "beginner_tutorials/Num";
  static final java.lang.String _DEFINITION = "int64 num\nint64 num2\n";
  long getNum();
  void setNum(long value);
  long getNum2();
  void setNum2(long value);
}
