package coursework.security.jwt;

import lombok.Getter;
import lombok.Setter;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

@Getter
@Setter
@Configuration
@ConfigurationProperties(prefix = "jwt")
public class JWTProperties {

  private String secretKey = "s3cr3tK3y";
  private Long validityInMs = 180_000L; // half an hour
}
