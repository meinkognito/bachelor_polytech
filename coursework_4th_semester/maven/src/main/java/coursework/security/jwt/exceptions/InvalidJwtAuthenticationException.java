package coursework.security.jwt.exceptions;

public class InvalidJwtAuthenticationException extends RuntimeException {

  public InvalidJwtAuthenticationException(String message) {
    super(message);
  }
}
