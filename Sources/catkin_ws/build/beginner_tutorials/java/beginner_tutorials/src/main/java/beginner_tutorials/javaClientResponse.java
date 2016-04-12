package beginner_tutorials;

public interface javaClientResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "beginner_tutorials/javaClientResponse";
  static final java.lang.String _DEFINITION = "int64 ret";
  long getRet();
  void setRet(long value);
}
