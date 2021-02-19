type input =
  | Name
  | Captain;

[@react.component]
let make = (~update) => {
  let (teamInfo: Team.t, setTeamInfo) =
    React.useState(() => ({name: "", captain: ""}: Team.t));

  let handleChange = (inputType: input, event) => {
    ReactEvent.Synthetic.persist(event);

    switch (inputType) {
    | Name =>
      setTeamInfo(currentTeamInfo =>
        {...currentTeamInfo, name: ReactEvent.Synthetic.target(event)##value}
      )
    | Captain =>
      setTeamInfo(currentTeamInfo =>
        {
          ...currentTeamInfo,
          captain: ReactEvent.Synthetic.target(event)##value,
        }
      )
    };
  };

  let handleSubmit = (update, event) => {
    ReactEvent.Form.preventDefault(event);
    update(teamInfo);
    setTeamInfo(_ => {name: "", captain: ""});
  };

  <form onSubmit={handleSubmit(update)}>
    <h2> "Register your team"->React.string </h2>
    <label>
      "Team Name: "->React.string
      <input
        type_="text"
        onChange={handleChange(Name)}
        value={teamInfo.name}
      />
    </label>
    <label>
      "Team Captain: "->React.string
      <input
        type_="text"
        onChange={handleChange(Captain)}
        value={teamInfo.captain}
      />
    </label>
    <button type_="submit"> "Join Queue"->React.string </button>
  </form>;
};
