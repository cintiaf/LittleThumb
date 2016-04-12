package beginner_tutorials;

public interface javaClientRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "beginner_tutorials/javaClientRequest";
  static final java.lang.String _DEFINITION = "string action\nint64 engineFL\nint64 engineFR\nint64 engineBL\nint64 engineBR\nint64 time\n";
  java.lang.String getAction();
  void setAction(java.lang.String value);
  long getEngineFL();
  void setEngineFL(long value);
  long getEngineFR();
  void setEngineFR(long value);
  long getEngineBL();
  void setEngineBL(long value);
  long getEngineBR();
  void setEngineBR(long value);
  long getTime();
  void setTime(long value);
}
