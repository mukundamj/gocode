package mystore

import (
  "net/http"
  "encoding/json"
  "log"
  "github.com/gorilla/mux"
  "strconv"
  "io"
  "io/ioutil"
  "strings"
  "fmt"
)

type Controller struct {
  Storage Storage
}

func (c *Controller) AllProducts(w http.ResponseWriter, r *http.Request) {
  log.Println("Begin processing endpoint /tenant/products")
  products := c.Storage.GetProducts()
  data, _ := json.Marshal(products)
  w.Write(data)
  log.Println("All products returned for the endpoint /tenant/products")
  w.WriteHeader(http.StatusOK)
  return
}

func (c *Controller) GetProductById(w http.ResponseWriter, r *http.Request) {
  log.Println("Begin processing endpoint /tenant/product/{id} for GET method")
  vars := mux.Vars(r)
  id := vars["id"]
  productid, err := strconv.Atoi(id);
  if err != nil {
    log.Fatalln("Error GetProduct", err)
  }
  product := c.Storage.GetProductById(productid)
  data, _ := json.Marshal(product)
  w.WriteHeader(http.StatusOK)
  w.Write(data)
  log.Println("Product for an id returned for the endpoint /tenant/product/{id}")
  return
}

func (c *Controller) UpdateProduct(w http.ResponseWriter, r *http.Request) {
  log.Println("Begin processing endpoint /tenant/product for PUT method")
  var product Product
  body, err := ioutil.ReadAll(io.LimitReader(r.Body, 512))
  if err != nil {
    log.Println("Error in reading body for UpdateProduct", err)
    w.WriteHeader(http.StatusInternalServerError)
    return
  }

  if err := r.Body.Close(); err != nil {
    log.Fatalln("Error in Body.Close() ", err)
  }

  if err := json.Unmarshal(body, &product); err != nil {
    w.Header().Set("Content-Type", "application/json; charset=UTF-8")
    w.WriteHeader(422) // unprocessable entity
    if err := json.NewEncoder(w).Encode(err); err != nil {
      log.Fatalln("Error UpdateProduct unmarshalling data", err)
      w.WriteHeader(http.StatusInternalServerError)
      return
    }
  }

  log.Println("Product ID is: ", product.ID)
  success := c.Storage.UpdateProduct(product)

  if !success {
    w.WriteHeader(http.StatusBadRequest)
    return
  }
  w.WriteHeader(http.StatusOK)
  log.Println("Product successfully updated")
  return
}

func (c *Controller) AddProduct(w http.ResponseWriter, r *http.Request) {
  log.Println("Begin processing endpoint /tenant/product/{id} for POST method")
  var product Product
  body, err := ioutil.ReadAll(io.LimitReader(r.Body, 4096))

  if err != nil {
    log.Fatalln("Error in endpoint /tenant/product/{id} for POST method", err)
    w.WriteHeader(http.StatusInternalServerError)
    return
  }

  if err := r.Body.Close(); err != nil {
    log.Fatalln("Error in adding product", err)
  }

  if err := json.Unmarshal(body, &product); err != nil {
    w.WriteHeader(422) // unprocessable entity
    log.Println(err)
    if err := json.NewEncoder(w).Encode(err); err != nil {
      log.Fatalln("Error AddProduct unmarshalling data", err)
      w.WriteHeader(http.StatusInternalServerError)
      return
    }
  }

  log.Println(product)
  success := c.Storage.AddProduct(product)
  if !success {
      w.WriteHeader(http.StatusInternalServerError)
      return
  }

  w.WriteHeader(http.StatusCreated)
  log.Println("Product successfully added")
  return
}

func (c *Controller) DeleteProduct(w http.ResponseWriter, r *http.Request) {
  log.Println("Begin processing endpoint /tenant/product/{id} for DELETE method")
  vars := mux.Vars(r)
  id := vars["id"]
  fmt.Printf("vars = %v, id = %v\n", vars, id)

  productid, err := strconv.Atoi(id);

  if err != nil {
    log.Println("Error in product id. Make sure the product ID is an int")
    log.Println("The API endpoint should be of the format /tenant/product/{id}")
    log.Println("where id is an int")
    log.Println("err : ", err)
    w.WriteHeader(http.StatusBadRequest)
    return
  }

  if err := c.Storage.DeleteProduct(productid); err != "" {
    log.Println(err);
    if strings.Contains(err, "400") {
        w.WriteHeader(http.StatusBadRequest)
    } else if strings.Contains(err, "500") {
        w.WriteHeader(http.StatusInternalServerError)
    }
    return
  }
  w.WriteHeader(http.StatusOK)
  log.Println("Product successfully deleted")
  return
}
