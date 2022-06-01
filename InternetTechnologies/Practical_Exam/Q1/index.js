function logData() {
  // getting the form data
  const name = document.getElementById("book_name");
  const author = document.getElementById("author_name");
  const price = document.getElementById("book_price");
  const publisher = document.getElementById("book_publisher");
  const category = document.getElementById("book_category");

  // Book Object
  const book = {
    name: name.value,
    author: author.value,
    price: price.value,
    publisher: publisher.value,
    category: category.value,
  };

  // Loging Data
  console.log("Book Object : ", book);
  console.log("JSON Object : ", JSON.stringify(book));

  name.value = "";
  author.value = "";
  price.value = "";
  publisher.value = "";
  category.value = "";
}
