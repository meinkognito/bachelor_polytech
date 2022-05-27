package coursework.web;

import coursework.entity.Client;
import coursework.service.ClientsService;
import java.util.List;
import java.util.NoSuchElementException;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

@RestController
@RequestMapping
@AllArgsConstructor
public class ClientsController {

  private final ClientsService clientsService;

  @PostMapping("/addClient")
  public Client addClient(@RequestBody Client newClient) {
    return clientsService.addClient(newClient);
  }

  @GetMapping("/clients")
  public ResponseEntity<List<Client>> getAllClients() {
    return new ResponseEntity<>(clientsService.listOfClients(), HttpStatus.OK);
  }

  @GetMapping("/client/{id}")
  public ResponseEntity<Client> getClient(@PathVariable("id") Long id) {
    try {
      return new ResponseEntity<>(clientsService.getClientById(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Client not found");
    }
  }

  @PutMapping("/updateClient/{id}")
  public ResponseEntity<Client> updateClient(@PathVariable Long id, @RequestBody Client Client) {
    try {
      return new ResponseEntity<>(clientsService.updateClient(id, Client), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Client not found");
    }
  }

  @DeleteMapping("/deleteClient/{id}")
  public ResponseEntity<Client> deleteClient(@PathVariable Long id) {
    try {
      return new ResponseEntity<>(clientsService.deleteClient(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Client not found");
    }
  }
}
