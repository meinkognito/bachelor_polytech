package coursework.web;

import coursework.repositories.UserRepository;
import coursework.security.jwt.JWTTokenProvider;
import java.util.HashMap;
import java.util.Map;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/auth")
public class AuthController {

  @Autowired
  AuthenticationManager authenticationManager;

  @Autowired
  JWTTokenProvider jwtTokenProvider;

  @Autowired
  UserRepository userRepository;

  @PostMapping
  public ResponseEntity<Map<Object, Object>> signIn(@RequestBody AuthRequest request) {
    try {
      String name = request.getUsername();
      String token = jwtTokenProvider.createToken(
          name,
          userRepository.findUserByUsername(name)
              .orElseThrow(() -> new UsernameNotFoundException("User not found"))
              .getRoles()
      );

      Map<Object, Object> model = new HashMap<>();
      model.put("username", name);
      model.put("token", token);

      return ResponseEntity.ok(model);

    } catch (UsernameNotFoundException e) {
      throw new BadCredentialsException("Invalid credentials");
    }
  }

}
