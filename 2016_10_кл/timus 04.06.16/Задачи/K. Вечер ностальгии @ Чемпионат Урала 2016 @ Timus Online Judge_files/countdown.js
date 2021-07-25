function countdown(countdownId, timeId, serverStart, serverEnd, clientStart, replace) {
	var countEl = document.getElementById(countdownId);
	var tmEl = document.getElementById(timeId);
	if (countEl == null && tmEl == null)
		return;

	var elapsed = (new Date()).valueOf() - clientStart;
	var serverCurrentDate = new Date(serverStart + elapsed);
	var timeLeft = serverEnd - serverStart - elapsed + 5;

	if (countEl != null) {
		if (timeLeft <= 10) {
			countEl.innerHTML = replace;
			var txtEl = document.getElementById(countdownId + "Text");
			if (txtEl != null) {
				txtEl.innerHTML = "";
			}
		} else {
			countEl.innerHTML = TimeLeftToStr(timeLeft);
		}
	}
	if (tmEl != null)
		tmEl.innerHTML = DateToStr(serverCurrentDate);

	var delay = 1001 - new Date(serverCurrentDate).getMilliseconds();
	setTimeout(function() {
		countdown(countdownId, timeId, serverStart, serverEnd, clientStart, replace);
	}, delay);
}

function DateToStr(date) {
	return format(date.getUTCDate(), 2) + "." + format(date.getUTCMonth() + 1, 2) + "." + date.getUTCFullYear() + " "
		+ format(date.getUTCHours(), 2) + ":" + format(date.getUTCMinutes(), 2) + ":" + format(date.getUTCSeconds(), 2);
}

function TimeLeftToStr(tm) {
	tm = Math.floor(tm / 1000);
	var sec = tm % 60;
	tm = Math.floor(tm / 60);
	var min = tm % 60;
	tm = Math.floor(tm / 60);
	return tm + ":" + format(min, 2) + ":" + format(sec, 2);
}

function format(d, len) {
	var str = d.toString();
	while (str.length < len)
		str = "0" + str;
	return str;
}
