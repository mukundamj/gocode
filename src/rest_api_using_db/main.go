package main

import (
  //"encoding/json"
  "log"
  "net/http"
  //"github.com/gorilla/mux"
  //"github.com/gorilla/handlers"
  "rest_api_using_db/mystore"
)

//Comment TODO
func main() {
  //setup router
  router := mystore.NewRouter()

  //TODO: If CORS(Cross Orgin Resource Sharing)  ability is required
  //add code here to specify allowed methods and origins which can 
  //access the API endpoints designed here. A typical use case is
  //when a javascript on a webpage is trying to access our endpoint
  //let's say /tenatn/products to list all the products.

  //spin-up golang server
  log.Fatal(http.ListenAndServe(":8000", router))
}
