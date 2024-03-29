@react.component
let make = (~setTeams) =>
  <button
    className="game-over-btn"
    onClick={_ =>
      setTeams(allTeams =>
        allTeams->Belt.List.filterWithIndex((team, index) => index != List.length(allTeams) - 1)
      )}>
    {"Next"->React.string}
  </button>
