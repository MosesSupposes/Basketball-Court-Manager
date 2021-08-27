@react.component
let make = (~teams: list<Team.t>) => {
  let renderTeamList = () =>
    List.map(
      (team: Team.t) =>
        <div key=team.name>
          <h1> {team.name->React.string} </h1>
          <p> {team.captain->(x => x ++ "'s team")->React.string} </p>
        </div>,
      teams,
    )

  <div className="team-list"> {renderTeamList() |> Array.of_list |> ReasonReact.array} </div>
}
