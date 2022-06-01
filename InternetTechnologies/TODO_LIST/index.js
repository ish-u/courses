function addTodo(event) {
  // preventing the Form Submission
  event.preventDefault();
  const inputValue = document.getElementById("todo-to-add");
  if (inputValue.value !== "") {
    // getting the TODO LIST
    const list = document.getElementById("todo-list");

    // creating a new TODO
    const newTodo = document.createElement("li");
    const span = document.createElement("span");
    span.innerText = inputValue.value;
    newTodo.appendChild(span);
    newTodo.id = window.crypto.getRandomValues(new Uint32Array(1));
    newTodo.style.userSelect = "none";
    newTodo.style.textDecoration = "none";
    newTodo.className = "todo-item";

    //adding event listener to cross TODO
    newTodo.addEventListener("dblclick", () => {
      crossTodo(newTodo.id);
    });

    // creating the Edit Button for TODO
    const editButton = document.createElement("button");
    editButton.className = "edit-button";
    editButton.textContent = "EDIT";

    // adding event listener to edit TODO
    editButton.addEventListener("click", () => {
      editTodo(newTodo.id);
    });

    // creatin the Delete Button for TODO
    const deleteButton = document.createElement("button");
    deleteButton.className = "delete-button";
    deleteButton.textContent = "x";

    // adding event listener to delete TODO
    deleteButton.addEventListener("click", () => {
      deleteTodo(newTodo.id);
    });

    // adding TODO and Delete TODO Button to the TODO LIST
    newTodo.appendChild(editButton);
    newTodo.appendChild(deleteButton);
    list.appendChild(newTodo);

    // reseting the Todo From
    inputValue.value = "";
  }
}

// Cross a TODO whose id is given (todo:id)
function crossTodo(todo) {
  const todoElement = document.getElementById(todo).children[0];
  if (todoElement !== null) {
    const status = todoElement.style.textDecoration;
    if (status === "line-through") {
      document.getElementById(todo).children[0].style.textDecoration = "none";
    } else {
      document.getElementById(todo).children[0].style.textDecoration =
        "line-through";
    }
  }
}

// Edit a TODO whose id is given (todo:id)
function editTodo(todo) {
  const todoElement = document.getElementById(todo);
  if (todoElement !== null) {
    const updatedTodo = prompt(
      "Enter New Value",
      todoElement.children[0].innerHTML
    );
    todoElement.children[0].innerHTML = updatedTodo;
  }
}

// Delete a TODO whose id is given (todo:id)
function deleteTodo(todo) {
  if (document.getElementById(todo) !== null) {
    document.getElementById(todo).remove();
  }
}
