package mystore

import (
  "net/http"
  "github.com/gorilla/mux"
)

var controller = &Controller{Storage: Storage{}}

type Route struct {
  Name        string
  Method      string
  Pattern     string
  HandlerFunc http.HandlerFunc
}

type Routes []Route

var routes = Routes {
  Route {
    "AllProducts",
    "GET",
    "/tenant/products",
    controller.AllProducts,
  },

  Route {
    "GetProductById",
    "GET",
    "/tenant/product/{id}",
    controller.GetProductById,
  },

  Route {
    "UpdateProduct",
    "PUT",
    "/tenant/product",
    controller.UpdateProduct,
  },

  Route {
    "AddProduct",
    "POST",
    "/tenant/product",
    controller.AddProduct,
  },


  Route {
    "DeleteProduct",
    "DELETE",
    "/tenant/product/{id}",
    controller.DeleteProduct,
  },
}

func NewRouter() *mux.Router {
  router := mux.NewRouter().StrictSlash(true)
  for _, route := range routes {
    router.
      Methods(route.Method).
      Path(route.Pattern).
      Name(route.Name).
      Handler(route.HandlerFunc)
  }
  return router
}
