use MyProducts;
var bulk = db.store.initializeUnorderedBulkOp();
bulk.insert(
(
  {
      "_id": 1,
      "name": "iPhoneXs",
      "description": "The phone with elegant design",
      "category": "Smartphones",
      "productType": "5.8 inch",
      "price": 999,
      "inStock": true,
      "manufacturer": "Apple"
  },
;

bulk.insert(
  {
      "_id": 2,
      "name": "iPadPro",
      "description": "Bigger than iPhone and smaller than MacBook",
      "category": "Tablets",
      "productType": "11 inch",
      "price": 799,
      "inStock": true,
      "manufacturer": "Apple"
  },
);

bulk.insert(
  {
      "_id": 3,
      "name": "iPadMini",
      "description": "Bigger than iPhone and smaller than iPadPro",
      "category": "Tablets",
      "productType": "8 inch",
      "price": 699,
      "inStock": true,
      "manufacturer": "Apple"
  }
);

bulk.execute();
