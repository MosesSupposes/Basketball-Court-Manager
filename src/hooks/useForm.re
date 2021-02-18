let make = (~inputs: int) => {
  let allInputs =
    Array.make(inputs, "")
    |> Array.to_list
    |> List.map(emptyString => React.useState(() => ""));

  let handleChange = (index: int, event) => {
    List.mapi(
      (i: int, input) =>
        if (index == i) {
          let (_, setValue) = input;
          setValue(_ => ReactEvent.Form.target(event)##value);
        },
      allInputs,
    );
  };

  let handleSubmit = (update, event) => {
    ReactEvent.Mouse.preventDefault(event);
    update(List.map((value, _) => value));
  };

  (allInputs, handleChange, handleSubmit);
};
